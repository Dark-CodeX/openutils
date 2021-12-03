pkgname="sstring"
pkgver="1.5.1"
pkgrel="7"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.hh")

sha512sums=(
  "9f7b2c99446cf0f10ec0a8c08e43521935c55049f216b72600bcde6b55cc5c7a18e333ea159d892f0b60c7cd6f2e976fca36c4928d0d043c293b2de308432c6a"
  "57b9ef00cb258d6f56b0784cf90bf00662c165f3c8d9bbf4f85bf6b85919d8a744d2bc9868b0ed6ecba43c6f7ff257d4a35af04d2537ee77429b0c88dd109443"
  "395695607b5788e493d54ec29460ec6d31378796f80296331020ffd4f9f4445c2ee4f3bcd3ad1400119d4e879adc3f7c06a76774aa4d941fdda4f5ff90099f1d"
  "c278b8bb676e5960f99f970639a86194f1843fb989b219e97972b8597e7156dbf34998450385b062962a94d0d522923cb4cf498ebf9a232841a0c864187dedea"
  "4793357268f4966aa5e39b841ae64dcede59fc1f3df867c715122843b1737c99ceca7786c556a697d7002402dd5d47369ad8d28118c3b8080677e883b9828035")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/sstring/sstring.hh"
  echo "Done!"
}
