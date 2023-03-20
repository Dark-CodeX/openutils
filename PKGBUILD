pkgname="openutils-array"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="Memory Safe Array Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-array')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/array/master/array/array.hh")

sha512sums=("d1072470a480b38227c07567fa2eb6830703430cd16706c45ebdc78f5ab3114031afba053bce6b5513024a6a8f926f6e107d56483b59a99aa90b011119e1ecb2")

package() {
	echo "Memory Safe Array Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/array"
	cp "${srcdir}/array.hh" "${pkgdir}/usr/include/openutils/array/array.hh"
	echo "Done!"
}
