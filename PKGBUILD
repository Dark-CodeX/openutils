pkgname="sstring"
pkgver="31.5.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=("a0b835163f5bef0b9adbd130c4cfe5f3aa06b98828bc6f7ae9eb898f3273d68173b4e65a347d069ffad6d5fc3cbd71a3730bf0bd937e3fba76bf906c823c4dce" "245ef0a69733a1d1f5b7e227d7ac9b9b9f12ae10c380daa81ab9f6f8766adb0b287bf3e9b79e7aa8e5f66135ed801c486c0cf037b4d99edafc7b5c0b1e51071e" "f201cf5b3147a3a50313b8cb4ec0d23784a33c5eb46c8befb21db7c0e430f016900e2de339e6ccc7776cc2b6e5973f289822d14651ba9b3774cc4eea3187a1d6" "d923c92da96c6ee89d7b17003ac4d041fdbe4e4bdd51cdc4f5e8889dca57256511beda7bd72dfa7ede012f8683088989aecadcb0d7387dc007893229999daee7")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
