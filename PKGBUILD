pkgname="sstring"
pkgver="12.2.3"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("b500ab8dba0db95ee54b2b269abc1270e3712521b2a6693983f7685e723097ce39849568d9b6c5f2137f09576a40e4356be66ef22b9ad573e47e2285f0511aff" "666684243ffd166c0861eec87446c75530f56ff2887732c80df1fde745215c060214639aa3af806de3362574283823c9eb7566febb7a41e4b0447ef5bb351b38" "d55f92e5773537cc121d31ae1aeda174c7a3046e08a3d07509de0529d1b2d9db3157474fc488af9665e9c911991721d2eb1e2ff5bb5689b7b71a1caf757f3029")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
