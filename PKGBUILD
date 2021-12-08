pkgname="vector"
pkgver="1.5.1"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("8bde3e812f91ac36d2afb620fd84c7fb2a2d7f588b648b2db6bd3ff756e1054ad5d61186e08414c14b0d172ddfbe218b84e0803ac8f49aa114d4fef1ba254401" "4667d79996427b0e5e5c1d8938e0dffe2e920b29894915ea3230145e40913dd649ee4efe111ed28be78c402dbb4b9ebb04236ff15c8a0b462ce74bbb5a2668e9")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}