pkgname="sstring"
pkgver="3.5.1"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("e2ed0a940022477c4c4933e9ad2173a9d64f1611a85fa93c19bac188281b039842d03c061fad98a39a82e68d79a55832f9eb24b1b95d4b37fa42ef9b1175124e" "1d7a538f8f6dceb62ab35dc0c6c7fad4e60f4039384f17b03e23835e19e32b9c838422947be3c115c732fe207c517bff423f508d283f2813ada04d8a5f32f52b")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
