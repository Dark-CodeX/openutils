pkgname="openutils-returns"
pkgver="1.0.0"
pkgrel="2"
pkgdesc="Memory Safe Value Returning Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-returns')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/default.hh" "https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/optional.hh")

sha512sums=("a9214e67c2149f9922d0767792674f3fbb67ce7bc0c191e547b988232f1196312e0a2bfef79e3e769b471fd33ad214f3982ef053902de60a4e635c105b89bb18" "77ec4d34ef43294ee52ed7953bc835f7af1706bc9c294fbb38437386a2bb34d16c0c49a17ad04ff296f2912a7b31189c9aed6fb1d568314ecd8abca624c0c546")

package() {
  echo "Memory Safe Value Returning Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/openutils/returns"
  cp "${srcdir}/default.hh" "${pkgdir}/usr/include/openutils/returns/default.hh"
  cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/returns/optional.hh"
  echo "Done!"
}
