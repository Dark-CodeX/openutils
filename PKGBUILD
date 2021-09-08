pkgname="sstring"
pkgver="5.0.0"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("e8c21ac099f067fd232c47e015d132d6a34d84376583fb64139795c46915e30f7561b3492d5fca08af896025bff8bd55c10b9ad15301e0ebe0185100f7338408" "e8c21ac099f067fd232c47e015d132d6a34d84376583fb64139795c46915e30f7561b3492d5fca08af896025bff8bd55c10b9ad15301e0ebe0185100f7338408" "e8c21ac099f067fd232c47e015d132d6a34d84376583fb64139795c46915e30f7561b3492d5fca08af896025bff8bd55c10b9ad15301e0ebe0185100f7338408")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
