pkgname="sstring"
pkgver="17.2.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("3da0766de22554c25244a77507b6b188dd7c38a80d38914b58bc375aa54fa15705b18285fec0304828e15225404a60a217a6ce96c4e0eb66129177384845037a" "7bb937e61e74c3ff6fa1ef1ea6197b2686d365a528c8ec77770a91f938fc2e63b7acd7cbb19706151c2bfa39608d749728e2a8181f13bf86e8c80c3d2dea8b46" "5da995ca7a1c1886a396ef2cd1c25c934b76222d3a345e0b2a0ceae6af19ec5fdd711def6e2f389238fd3087e379a9c13700f7d756eec3ee7b5c79368c66ee7f")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
