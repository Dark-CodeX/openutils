pkgname="sstring"
pkgver="34.0.5"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=("02f6b69683070ba0ea3b390829dd7eaa85cae324866bcdc8622302e0ae39ee21b24d71a47d90ca1471ac75d43ef0afe1925f022e67dda836744703890ba9b938" "2d687b7a65747414f53f066d40d1a013de597429cc68d333182638e34f4a30b5d1fcb5e2e85fa7397dc6f828cc7aec9f126b58d02f3ee5bc7aadaeeaa098cc7e" "618c5ec72847f752f6a5f949e0941e84875044c187b0bb9d0b31cd8108bb6cef93c78b0159d861f41153b9bf157d7161793a9f9455c2319f2161ba18a849255d" "9a7343c81e726975f205ef80bf83dae59a32c815833975d1c4f86b2a5dd6eea8e7884c93d0d07206d0d5c1c4877db01fdebbd991bc6c2c249dae6d84d923c246")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
