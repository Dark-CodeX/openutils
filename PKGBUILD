pkgname="sstring"
pkgver="21.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("c17d5eea09e61be03a8b444ef6c15976310441cb8b4b746783bb83575c36e8363b39b670cf1e80fce6846cbea0c9a00346267ed174ee695f1fb7459fbcab741a" "ace61a008f9eb9bada9a3b5f24c41f3517803ec8b81ca75e4a16c44aa974ff64a32b0b219a90e3c731a9c3ba4e7f22ab7a40ef2a51053ac4fb6f80972575c27b" "fa2af8fc748c93e95806e91fb736039d84c61fb94a44f3f9569f416b79f6b3395a888d020157d620ca645587c6b0b775b45dcfee8580312932943cf03c76f463")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
