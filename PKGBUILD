pkgname="openutils-vector"
pkgver="1.5.4"
pkgrel="4"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("c0f12375ed15f6bfb2a1940821b5117b2d7686b06c7cdc8bac55ee67cbc86e419ee8721c13ab4de8814e3e30e042de805e72b28c6ff28b0a3b51945fbad6d1a8" "b7876b50e3427aa5845bcaa97f651697a7c868918762d9319c1ec7f8d5098e12a87d450933990833b2f295d8e50df0534cebbe5afe35f4e755727b423626712b")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/openutils/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
  echo "Done!"
}