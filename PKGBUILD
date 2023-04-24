pkgname="openutils-array"
pkgver="2.0.0"
pkgrel="1"
pkgdesc="ARRAY : The Non-Resizable Array Library"
arch=("x86_64" "i686")
conflicts=('openutils-array')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/array/master/array/array.hh")

sha512sums=("c7ef8b56602c8466e036147dcda81d66281830f387cfdcf27249ca33ae073c1e4b47f56f22dd4531f4d033d5afc90eb8593106d17b7edfa17cd78973c0d4c54c")

package() {
	echo "ARRAY : The Non-Resizable Array Library"
	mkdir -p "${pkgdir}/usr/include/openutils/array"
	cp "${srcdir}/array.hh" "${pkgdir}/usr/include/openutils/array/array.hh"
	echo "Done!"
}
