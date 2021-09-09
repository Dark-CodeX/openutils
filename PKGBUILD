pkgname="sstring"
pkgver="5.3.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("e8aba07d85d91a151406b8a0234844704457eb4338ba5705365e6ab4809278b5c87f24283944dd419dd65f06383c1e370c17ecbab94b0b6efa6abf9c1a10ef09" "efaa8a3b8735046ebd2dcf209d43fca502a3710dcbcdcacd7c6d35b3cf5d83357af9e02a53e168153596be167939aa76129e6217ca80cbe02815c3b33c50879c" "668cdf5083d9197781994420ffa86c79b5f27dee8796b11c83caffcd72aaa0c49ff584d9d6785e942c88b6b67580d95a73485e685b8dc9977e23d16e538ab52d")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
