#include <iostream>

#include "absl/strings/string_view.h"
#include "opencensus/exporters/trace/zipkin/zipkin_exporter.h"
#include "opencensus/trace/sampler.h"
#include "opencensus/trace/span.h"

std::string processLine(const opencensus::trace::Span& parentSpan,
                        const std::string& in) {
  auto span = opencensus::trace::Span::StartSpan("processLine", &parentSpan);
  std::string out(in);

  for (auto it = out.begin(); it != out.end(); it++) {
    *it = std::toupper(*it);
  }

  // Add a custom annotation to examine later on.
  span.AddAnnotation(out);

  span.End();
  return out;
}

int main(int argc, char** argv) {
  // Samplers are potentially expensive to construct. Use one long-lived
  // sampler instead of constructing one for every Span.
  static opencensus::trace::AlwaysSampler sampler;

  // Initialize and enable the Zipkin trace exporter.
  const absl::string_view endpoint = "http://localhost:9411/api/v2/spans";
  opencensus::exporters::trace::ZipkinExporter::Register(
      opencensus::exporters::trace::ZipkinExporterOptions(endpoint));

  while (1) {
    opencensus::trace::Span replSpan = opencensus::trace::Span::StartSpan(
        "repl", /* parent = */ nullptr, {&sampler});

    std::cout << "\n> ";
    std::string input;

    opencensus::trace::Span readLineSpan =
        opencensus::trace::Span::StartSpan("readLine", &replSpan);
    std::getline(std::cin, input);
    readLineSpan.End();

    // Let's annotate the span.
    replSpan.AddAnnotation("Invoking processLine");
    const std::string upper = processLine(replSpan, input);

    std::cout << "< " << upper << std::endl;

    // Always explicitly End() every Span.
    replSpan.End();
  }
}
