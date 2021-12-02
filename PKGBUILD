pkgname="vector"
pkgver="25.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("d901fc919e4a633d4400e8f00f705c806213134db936ca680cb87f8aeb06b917f3f44b6fdfd39dfd0bd987c3897ea6a98961cf96fdb06a415258978f2e48fe78" "9429f30a62ad3c4c00ccd74f1ea24e1000d3602bc08a3ec83278d23cc6cbee279aa6a091210f8d89e0fd316691b41c5842995c482e64be47d5f4559c1d969702")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}