pkgname="openutils-array"
pkgver="2.0.0"
pkgrel="1"
pkgdesc="ARRAY : The Non-Resizable Array Library"
arch=("x86_64" "i686")
conflicts=('openutils-array')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/array/master/array/array.hh")

sha512sums=("8652685eaf38dbdab076c05fc7e36b726a2f55c4ce382e08ddb38a4c80d228419658e0fc8144125fe716ed07f642a3d6ef4e9d14331d09a551b316a18840b848")

package() {
	echo "ARRAY : The Non-Resizable Array Library"
	mkdir -p "${pkgdir}/usr/include/openutils/array"
	cp "${srcdir}/array.hh" "${pkgdir}/usr/include/openutils/array/array.hh"
	echo "Done!"
}
