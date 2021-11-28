pkgname="sstring"
pkgver="49.1.1"
pkgrel="7"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.hh")

sha512sums=(
  "869ab0257797386d7a31a13f00907627701a8872fc16362000129aa575fc47fcad4d972ed3cd424f56a108ebb2f575557b5648fd68e249adc116b1ffa6d26ed8"
  "e3ed156a59806df3c64acc8a1f2d14331cce9baf27ba0ac23fd5d7a85c96662b10048fc8ea6fde8a385711979a08ae4efe3f7d0cec4fcf0b02ea93c1215b5def"
  "197a4fa1d2282604eccb05348c4756766982407e9b4cf9e49847cba7ab28ea657283819f3ee84bee115832b163d4f6ef6e2ff21ea7dec260698edf02a96c28e1"
  "7a26a9eaa3fa498f30956994c0c50b743d3e93b56c880cfc308f21f093ee294058943356d074069bf7627c2797c6ef77a8d760d7e9b87c1c982a208eb0f92834"
  "a31515a3f48683125410d07cc337a4593306512a87d0ed3523d7968a20ffdd1272753aa68f80e42e00722061b127643447a00769dc2eee66d65409315aa9d7fb")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/sstring/sstring.hh"
  echo "Done!"
}
