pkgname="sstring"
pkgver="7.7.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("5bbd8078aa82d9b46f6e5f66c5f4a8e25b159c8f3847bd665b007d3ceb5d70a80474f827f7125e404828290ce93c6fd241793595a5df68525054484bb3099918" "331beecbf720b116f4e1176905a59382ca66fcf03970d04dc85ba0a023e18e1dcda141d3b5906e34c9d6ebb681e00d34b4a9bf2286e7a5e1559f7d1e497784ca" "970b1b767063e3d7f2171a25eb1cb9592fbf111136dac931ad08b90563e98c867b55b6eea50e4f73eceffdb7b6155cc1d69fa713c5c50c279f95deac384c7db8")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
