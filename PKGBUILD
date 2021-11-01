pkgname="vector"
pkgver="14.0.0"
pkgrel="2"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h")
sha512sums=("1a4bb31c4f225ade7e46bec62494fa6a39c73993b2522cc6c3c7a0a8f26ba4437c3677edc06d3b2fabe9d36aa3e4f86e1c4e517c7db5d2a726b6d14919af17b1")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  echo "Done!"
}