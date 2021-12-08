pkgname="vector"
pkgver="1.4.7"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("c0cde868c8ff77bca363076cc91c784c3c3ca188891b7dae0061c0bef36f6ce9a83961f1a1e816c4b391128a2c65e0b138fa5f27e79244ad4c68362ac4b252ff" "2ae7a2f3dccadc056b0c77e0e6b582311a306a8a806663971170f868de7f4bf17f5ebe110b13ba36cf3e9f1cce95ed002d3c7c48b14f8261f1e7e783301f5933")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}