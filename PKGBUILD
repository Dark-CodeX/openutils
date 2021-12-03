pkgname="vector"
pkgver="1.4.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("86b780b79a1d2df7761edf3ccb1598d938933b0e4ccaa91daaadeaeee04aef83261bf1f3771fc1a95fdc509f6ce35aa1c6afaff33cafdbd284e49954608e91aa" "853113ccf42098386c2b1aa3915de4d9cc501c49b8f7e36115cae531c23fbad377497e56c29a2df7d844f677532c7f66196dd56b7f516219430e352fe97d4413")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}