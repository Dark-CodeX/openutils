pkgname="vector"
pkgver="10.0.0"
pkgrel="2"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h")
sha512sums=("4bf32c4ba168b38756eb965bd6dc2bf72e3308088f81c0b06cc62fec6d13ea36c740d172f88b58d017880e693bbd7b27bd2437a9db556c76d573915543db365d")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  echo "Done!"
}