pkgname="openutils-array"
pkgver="2.0.0"
pkgrel="1"
pkgdesc="ARRAY : The Non-Resizable Array Library"
arch=("x86_64" "i686")
conflicts=('openutils-array')
depends=(gcc)
license=("GNU GPL v3.0")
source=("https://raw.githubusercontent.com/Dark-CodeX/array/master/array/array.hh")

sha512sums=("62d3610e0367967704fcce842b5768709e25768cd683e7f0367a92acbdc38fb026c7aa15647c6340f8c4dddaa80c6057c53520d65bf70747016761d35deb32f2")

package() {
	echo "ARRAY : The Non-Resizable Array Library"
	mkdir -p "${pkgdir}/usr/include/openutils/array"
	cp "${srcdir}/array.hh" "${pkgdir}/usr/include/openutils/array/array.hh"
	echo "Done!"
}
