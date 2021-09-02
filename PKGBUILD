pkgname="sstring"
pkgver="3.0.1"
pkgrel="2"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h")
sha512sums=("a30aa7b1f3283ad16908f5e3ae0d576567dd2f1a9ee08e597c36c65f7ded7fb38c906161070f2e6906d08b35a2cae841e94e587ee116b4acb08fa15593835748")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  echo "Done!"
}
