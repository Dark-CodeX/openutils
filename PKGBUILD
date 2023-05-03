pkgname="openutils-array"
pkgver="2.0.0"
pkgrel="1"
pkgdesc="ARRAY : The Non-Resizable Array Library"
arch=("x86_64" "i686")
conflicts=('openutils-array')
depends=(gcc)
license=("GNU GPL v3.0")
source=("https://raw.githubusercontent.com/Dark-CodeX/array/master/array/array.hh")

sha512sums=("0f3dcdb453c71e9dc7b4a74e74102fd26491b36f75ffccd4e623ffa2b0d618d6e3af9801ece077a6f2b568b82a843339e0082fe902f2df40afe57011e8f747e8")

package() {
	echo "ARRAY : The Non-Resizable Array Library"
	mkdir -p "${pkgdir}/usr/include/openutils/array"
	cp "${srcdir}/array.hh" "${pkgdir}/usr/include/openutils/array/array.hh"
	echo "Done!"
}
