pkgname="vector"
pkgver="1.4.9"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("bacc73f9ed48258e610a9dcef5ee4ec02dac7f9dbf8bccb0cd72a772d499622d22ea422b061847b0b0e541247697eaa991e82c6f1767e11fbbb3fb9a6c6feddc" "b55bfc592b6d554d3c82aebe8672763d2c4d61594508bd0268f12ed83ebfea0b825416d0e358b6456025033b6399f39cc3a011f4e4bf561e8787e495ee56aba5")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}