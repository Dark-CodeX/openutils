pkgname="openutils-heap_pair"
pkgver="1.2.0"
pkgrel="1"
pkgdesc="HEAP-PAIR : The Pair Management Library"
arch=("x86_64" "i686")
conflicts=('openutils-heap_pair')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/heap-pair/main/heap-pair/heap-pair.hh")

sha512sums=("d443a879b8c83abf26f65f8b44fb74dbf435066401c8454ec85d8d2ec3db246427bbdb728910962f5bc31f86a388016e4434dfeba4e84cbffa48c561c5c357c7")

package() {
	echo "HEAP-PAIR : The Pair Management Library"
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
