pkgname="openutils-returns"
pkgver="1.0.0"
pkgrel="2"
pkgdesc="Memory Safe Value Returning Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-returns')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/default.hh" "https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/optional.hh")

sha512sums=("c5197edb8c599177ee3b527036556b06478b992d519e016bc0f0f88d5f40ec9f25185889eb1bb9b45cf7f44e425f3b15a4466a5c237f3fa6f69cdc1e3cbaedd8" "329493ce25ecf0304454e25a42e6f979f231d3f19d411ab50d37496c7dd429ce103e0c2c1eea16b4245a5fc2951654e540f5d55bdc9e8160af0de6012c11fcef")

package() {
  echo "Memory Safe Value Returning Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/openutils/returns"
  cp "${srcdir}/default.hh" "${pkgdir}/usr/include/openutils/returns/default.hh"
  cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/returns/optional.hh"
  echo "Done!"
}
