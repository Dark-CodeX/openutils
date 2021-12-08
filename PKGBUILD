pkgname="vector"
pkgver="1.4.8"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("5db6df34fa63ee1feb7e11da30f303e646bbf579a182da7c10805a0354031d061e74a0e5876567ad0bcbefa0a3d8f02e4badf408394fe443715c58e383df6e5b" "6039035d150187c4d3e8387f4360b02fec2e6fb69a6ce905315f3c7c0b46b568ac02700a9bc24500fe88bb46181d61ec6fe845b40a4823417a2e2c79ba6adcd5")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}