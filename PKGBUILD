pkgname="vector"
pkgver="11.0.0"
pkgrel="2"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h")
sha512sums=("347de0b23a0050afdc5268f0f0381f7094bb5b8205bbc42ffa842f6755f6d38390e863973efd798b121ea90974ee06fb30c0023eac41c1388a0e31601c807d3d")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  echo "Done!"
}