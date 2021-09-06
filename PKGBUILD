pkgname="sstring"
pkgver="4.1.2"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("4d5b3d05147e3393b5503b8f211e91905c1cca0b971beac380f4311bd8f96a13a75d52fff490e05247ed07063b6b6ea8a22bedc089923b3bda9a414c44923347" "f804d1028763c56881a6aae3cd4389a037e5c91b429a37ebf8e42be67a9587a99b0ada11467bd0e77b31c19d7cd0da07544d83cd5780434d1c044c2bec6fe9f9")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
