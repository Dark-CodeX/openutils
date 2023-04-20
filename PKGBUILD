pkgname="openutils-optional"
pkgver="1.6.0"
pkgrel="2"
pkgdesc="OPTIONAL : The Error Handling Library"
arch=("x86_64" "i686")
conflicts=('openutils-optional')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/optional/master/optional/optional.hh")

sha512sums=("1449950d1ce36d85f98267521244150654c0c7fee6d4782cc7f6ef785ffb1a3b7a96fd93813202265884d41fd6a9b1c7a71733d2d63b8277881253bb0f9a7328")

package() {
	echo "OPTIONAL : The Error Handling Library"
	mkdir -p "${pkgdir}/usr/include/openutils/optional"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/optional/optional.hh"
	echo "Done!"
}
