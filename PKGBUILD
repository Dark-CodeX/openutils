pkgname="openutils-returns"
pkgver="1.0.0"
pkgrel="2"
pkgdesc="Memory Safe Value Returning Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-returns')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/default.hh" "https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/optional.hh")

sha512sums=("30541e2a9c79c633e50d6388b78afe42515b2e90ca24d6cd9a161b56834a1eda04739db4dc562204d9210cae658fcb78d72529488828f0c4b0d96265ede8834e" "8f900a0eab09bf9cb8f8b36d7d50b8461b70ef9d78076b854664601f07206244300644987f70e72ff1d6888da813a4481dfbce82cd3b76e829b9f8afe461704c")

package() {
  echo "Memory Safe Value Returning Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/openutils/returns"
  cp "${srcdir}/default.hh" "${pkgdir}/usr/include/openutils/returns/default.hh"
  cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/returns/optional.hh"
  echo "Done!"
}
