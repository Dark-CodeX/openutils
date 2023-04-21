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

sha512sums=("56dfe97df2a3ef6a3688e9f9008baf57a256dd2420607e50b9d7f4205f563401e20109fffafdc884f05da0d5aaee8e55bdf2273e326b24d9846091c7736b3677")

package() {
	echo "HEAP-PAIR : The Pair Management Library"
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
