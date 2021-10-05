pkgname="vector"
pkgver="10.1.0"
pkgrel="2"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h")
sha512sums=("ff7057dc7534ee4075be43ae2607e2b1b82a0905647c1770007351353771d9f9bf2cba992fccf4882d863136d81b8e4939e77f942156ed8fa104f11669ce5407")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  echo "Done!"
}