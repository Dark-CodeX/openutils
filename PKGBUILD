pkgname="sstring"
pkgver="12.2.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("0727976c4885fe208133ee05f004f65f641e0a720ca26ab8b5b7bbd733291b25f554ce29a9518a2a009c5363d0c743566a8a41316d5e418898d8f45946e27034" "8470ce21ffd48a8725d6d830ae3595e168202736388ef9870b2d52b0622e2b6364eaae98bc01ff9caff2bcc17781354203b0722e05ab8510b9ed9187a86ad57d" "8f878831063c16553d93abf45206d9903d86c0701a71cf75ad6547d58cdcfae91e6ce159fed79909c0cc4b7eb0b8e1f2f7335ceffa69fd0aa80c492f4e67161c")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
