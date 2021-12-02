pkgname="vector"
pkgver="28.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("d3c90b761404276ae1c338daaa6ec281eb504cc9c5a189baedf6ac9f04bfab00fc0a1e0bd39f031eeda287102d511900a9cf0e19b9526613e3adeace95cb7fa1" "aabfae36e4dca6f493b5685b1204b5b3849f76573a6b155b645240af874fa2f7e321fcf46114026fa9991a56ee92e76d6a9f5df97a84181a908346dbb4d342f9")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}