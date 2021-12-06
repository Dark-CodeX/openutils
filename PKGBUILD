pkgname="vector"
pkgver="1.4.6"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("53404b250aa5996086d69920ea8fba49b525a232bf8a922610f608fd130f78f8071e505b6950d7d393337b684668a945f21fb903ef4a8569d26d408783fac66d" "aff75d338d5dcda04084f853eff2c1924368a1d1ea77bc94b3f49c56f0395966d961e0e39eb23e574981606200a36dcfb17e17dbb249fde0b41e144a674b74dd")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}