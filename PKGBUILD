pkgname="openutils-array"
pkgver="2.0.0"
pkgrel="1"
pkgdesc="ARRAY : The Non-Resizable Array Library"
arch=("x86_64" "i686")
conflicts=('openutils-array')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/array/master/array/array.hh")

sha512sums=("bf1c1f51a39340645a540eba22f2614be3729c4f8d3ddb8fcd8c3a0bb4aca21631644a029a0ae43669cfee951008cd67999fccb3d24f02599929e668af58ea1b")

package() {
	echo "ARRAY : The Non-Resizable Array Library"
	mkdir -p "${pkgdir}/usr/include/openutils/array"
	cp "${srcdir}/array.hh" "${pkgdir}/usr/include/openutils/array/array.hh"
	echo "Done!"
}
