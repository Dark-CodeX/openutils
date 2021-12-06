pkgname="vector"
pkgver="1.4.5"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("7499215b932a8ec04cea6941cf48c18277b34b475ab2927b45d99127de9d85848ac6b955d3d99c749f8b22fafc10d775a6fc7de86748381a171f0241f18ed486" "f478adc29a4618f345bde745e511e29100c98f7915fc1bc9be6677f8a2330846654b85293d3ea6c7d2ea587c401cf74e9564b50240bf74a1d681e5e4695d7ccb")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}