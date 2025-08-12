#include "ReferenceManual.h"
#include "ColorCoder.h"
#include <sstream>
#include <iomanip>

std::string FormatReferenceManual() {
    std::ostringstream oss;
    oss << std::left << std::setw(8) << "Pair #"
        << std::setw(15) << "Major Color"
        << std::setw(15) << "Minor Color" << "\n";
    oss << std::string(38, '-') << "\n";

    for (int i = 1; i <= TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors; ++i) {
        auto colorPair = TelCoColorCoder::GetColorFromPairNumber(i);
        oss << std::left << std::setw(8) << i
            << std::setw(15) << TelCoColorCoder::MajorColorNames[colorPair.getMajor()]
            << std::setw(15) << TelCoColorCoder::MinorColorNames[colorPair.getMinor()] << "\n";
    }
    return oss.str();
}