pkgname="vector"
pkgver="20.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("e762aeedd5f58db3e8a360f4601fee5f45c0386b62266e12a17a96ee871adfe44ffddee76a5fe5e4fb275e6a60151ddf5b3a0b66221fa8cfc0ef2f8f0985b7bc" "0323b6824c6b5eeb14f09707724018d2a28103095dfe78069594c1d66d3a10e57916074ca37335239ddd181a28efe9eb2eb7060e2eaa2649eea844ea93ba6c69")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  echo "Done!"
}