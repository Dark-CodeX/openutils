pkgname="sstring"
pkgver="1.1.2"
pkgrel="1"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h")
sha512sums=("0734efd4cdceabcc718c52e297d7f978a4c57577287c69c6b0edfa731d954b30d0a8edaf3c07b4c7138140394800a06fe26189eb5fca93248bc905e2b4a493d2")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  echo "Done!"
}
