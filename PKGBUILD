pkgname="openutils-returns"
pkgver="1.2.0"
pkgrel="2"
pkgdesc="Memory Safe Value Returning Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-returns')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/default.hh" "https://raw.githubusercontent.com/Dark-CodeX/returns/master/returns/optional.hh")

sha512sums=("437dab323b70d1f958edc9620e3afa1a23b4831d8ca943a033500195c97ea4a3505f12918beb16c279aba4c1508971ed447e87e6e52c0e0e0b92692e07cd26e4" "339e4bdbaca880758ee0fb30d49d6441166748e13a8ff5e592e36d4c37306a6fda9796f18e561cd9e591aa3f26fc635a75cc68b080efa0bb6bf372d432f88421")

package() {
	echo "Memory Safe Value Returning Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/returns"
	cp "${srcdir}/default.hh" "${pkgdir}/usr/include/openutils/returns/default.hh"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/returns/optional.hh"
	echo "Done!"
}
