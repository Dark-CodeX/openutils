pkgname="sstring"
pkgver="4.2.5"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("1062188af9c68218d27f4f8c60c4dfffa66c99a35785a9b9e52958c3d3d84284dd161aead698bc75634636b99a13c097c0eafe4dcab9b6fedc7cdc54d1508f4f" "295d61e3b8d2cc5cbcede4b5ba90c3c25a6bb17a494b3eb34a697d56f241678913a91771ed9cf2d5e231fbbd971e78b5e9c1f8f07b473e84e0af28b51d04b44b")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
