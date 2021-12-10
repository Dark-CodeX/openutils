pkgname="vector"
pkgver="1.5.2"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("f152b8e42a9e219a8949b95e6bcc9bcd5676dfa808ac7d50f5711a0d61b0858e94251c1b3eff2a79dac5aa5a88fd218a34f3111aabee98ae249e009f0b88938f" "218fb6b503fd96d171edd35f56a28853f9d299fee843694bdca577fda1a9d53dadd0ac914a92e12f492656bf498c0431d5d036270af69158b80653c5903dd457")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}