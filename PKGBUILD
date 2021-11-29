pkgname="vector"
pkgver="23.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("f4a0830bb8687220e7a8300d6eb9f22906d39c7d3aa798f7596ab723bf572a21b297acd9665f2c32dbe844523177c8e9ea9f19ae0481d45a3001fffc552ba92d" "5e5aa47a3072ae08fb4eabf5c19f0781f3861a6b781715d25fdc94830eb3f8b83b67d9195c51e63918c2b870b63e54157a5a1e36b423ebc47317b168adbd9fe4")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}