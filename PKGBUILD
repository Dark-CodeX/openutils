pkgname="vector"
pkgver="1.5.1"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("8bde3e812f91ac36d2afb620fd84c7fb2a2d7f588b648b2db6bd3ff756e1054ad5d61186e08414c14b0d172ddfbe218b84e0803ac8f49aa114d4fef1ba254401" "be8007c3363cf1c50d33ceaa3ef81710d7730fd7a62f3c343d43e081e4d8193c71957f7628f1eeadd2adef6f50111cc649a2ffa47d1aba747c0d9e34956feed8")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}