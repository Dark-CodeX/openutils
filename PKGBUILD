pkgname="sstring"
pkgver="5.5.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("2eab08538a32f50a39d1cca3d67dbb7beb113d8da2089fcf98bf61266067ec0c64ecf64ac7af7f796e0c472baed5aca8d07de0dfe91b0d15ea95657913180316" "c3b03e355df0a8255f911bcaf79c9d1d763611eb55f674066ea399ee4f1e06b31ef24f6f51aedacb336a1ad24c72c73ef224880d3ec8004c3757f955711ae20d" "cc1f7bd7c54f9831e7a0b0730992dc49ee08227a093c1c2c8d38f4a9ff0d50124889b1d0a6bde2c01b8cfb8826a61cad8ba6646d9b4d6bbc93d7201ac28a7dcd")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
