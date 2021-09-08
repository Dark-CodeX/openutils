pkgname="sstring"
pkgver="4.3.0"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("4901a6f0e03328255f49e4d7c19852c4a93c55d41b553874973e6556602610cb80a9aca04fde0f05c22f79c0b46241a7bdca50a451cac6d8c3a8cf02c109f14c" "89e0a1818018da1a6a36ad320cacc72165ddb6485df3193e5e4575d24f0dac1b6a0215336b60de13bf747b2b85f90bdd5520b31ee804517bef021a441d8ecb25")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
