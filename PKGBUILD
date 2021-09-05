pkgname="sstring"
pkgver="3.7.1"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("34fa3e86f00dd28c4046a438213485e734e793052370893bb1a665aae88903f2b7efef96a326d9df90efb6252fcdea6f790b28a4c54824072c88399d6afc4191" "9b8275447b9038b251ac953efa7bac065e5bb26f7f6ecf01ec112f20930eb24b264f38f1da7518c841670e8bacff8b4fa886e638a55a921db191475ef780e0b9")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
