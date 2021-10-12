pkgname="vector"
pkgver="12.0.0"
pkgrel="2"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h")
sha512sums=("58caac190e67c6eaa86fb766c0578dc68104477cdaff036af9e81fa6103f693599f60a3f292c7d165486f55e8f8689aa288d0a3a0a7a01f137267836309cf1cf")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  echo "Done!"
}