pkgname="sstring"
pkgver="24.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("6b5e182a2f9c25f30366074eb8ca09d99d96b6f4301d727b0464086f6936e820a90db71956e72645c79a740849e919fd3c93aab4553de5d34bb9a6d9d8f6bc5a" "e8ac662bc824158620f1eb365840b5766704c1360c04448e55cf1a4782ec6d354cde1b06af3c30981be32014dad5b86870844a91cd116d1e20aec5e007576f57" "41e490dda2757396e744c57e6e69076b439514d7a90ba7f0975649d15af19a67e010028fa9c995bcfe2818af68778838946596dbbb0ac75797b03c3b1e0591fc")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
